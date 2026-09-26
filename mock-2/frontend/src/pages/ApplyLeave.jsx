import { useState } from "react";
import { useNavigate } from "react-router-dom";
import api from "../services/api";

function ApplyLeave() {
  const navigate = useNavigate();

  const [form, setForm] = useState({
    leaveType: "CL",
    startDate: "",
    endDate: "",
    reason: "",
  });

  const handleChange = (e) => {
    setForm({
      ...form,
      [e.target.name]: e.target.value,
    });
  };

  const handleSubmit = async (e) => {
    e.preventDefault();

    try {
      const response = await api.post("/leaves", form);
      alert(response.data.message);
      navigate("/employee/dashboard");
    } catch (error) {
      console.log(error);
      alert(
        error.response?.data?.message ||
          "Leave application failed"
      );
    }
  };

  return (
    <div className="container mt-5">
      <div className="row justify-content-center">
        <div className="col-md-6">

          <div className="card shadow-sm">
            <div className="card-body">

              <h2 className="text-center mb-4">
                Apply Leave
              </h2>

              <form onSubmit={handleSubmit}>

                {/* Leave Type */}
                <div className="mb-3">
                  <label className="form-label">
                    Leave Type
                  </label>

                  <select
                    className="form-select"
                    name="leaveType"
                    value={form.leaveType}
                    onChange={handleChange}
                  >
                    <option value="CL">
                      Casual Leave
                    </option>
                    <option value="SL">
                      Sick Leave
                    </option>
                    <option value="EL">
                      Earned Leave
                    </option>
                    <option value="PL">
                      Privilege Leave
                    </option>
                  </select>
                </div>

                {/* Start Date */}
                <div className="mb-3">
                  <label className="form-label">
                    Start Date
                  </label>

                  <input
                    type="date"
                    className="form-control"
                    name="startDate"
                    value={form.startDate}
                    onChange={handleChange}
                  />
                </div>

                {/* End Date */}
                <div className="mb-3">
                  <label className="form-label">
                    End Date
                  </label>

                  <input
                    type="date"
                    className="form-control"
                    name="endDate"
                    value={form.endDate}
                    onChange={handleChange}
                  />
                </div>

                {/* Reason */}
                <div className="mb-3">
                  <label className="form-label">
                    Reason
                  </label>

                  <textarea
                    className="form-control"
                    name="reason"
                    rows="4"
                    placeholder="Enter leave reason"
                    value={form.reason}
                    onChange={handleChange}
                  ></textarea>
                </div>

                {/* Button */}
                <button
                  type="submit"
                  className="btn btn-primary w-100"
                >
                  Apply Leave
                </button>

              </form>

            </div>
          </div>

        </div>
      </div>
    </div>
  );
}

export default ApplyLeave;