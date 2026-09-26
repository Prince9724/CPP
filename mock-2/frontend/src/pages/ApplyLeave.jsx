import { useState } from "react";
import { useNavigate } from "react-router-dom";
import api from "../services/api";

function ApplyLeave() {
  const navigate = useNavigate();

  const [form, setForm] = useState({ leaveType: "CL", startDate: "", endDate: "", reason: "",});
  const handleChange = (e) => {setForm({ ...form, [e.target.name]: e.target.value,});};
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
    <div>
      <h1>Apply Leave</h1>

      <form onSubmit={handleSubmit}>

        <div>
          <label>Leave Type</label>

          <select
            name="leaveType"
            value={form.leaveType}
            onChange={handleChange}
          >
            <option value="CL">Casual Leave</option>
            <option value="SL">Sick Leave</option>
            <option value="EL">Earned Leave</option>
            <option value="PL">Privilege Leave</option>
          </select>
        </div>

        <br />

        <div>
          <label>Start Date</label>

          <input
            type="date"
            name="startDate"
            value={form.startDate}
            onChange={handleChange}
          />
        </div>

        <br />

        <div>
          <label>End Date</label>

          <input
            type="date"
            name="endDate"
            value={form.endDate}
            onChange={handleChange}
          />
        </div>

        <br />

        <div>
          <label>Reason</label>

          <textarea
            name="reason"
            placeholder="Enter leave reason"
            value={form.reason}
            onChange={handleChange}
          />
        </div>

        <br />

        <button type="submit">
          Apply Leave
        </button>

      </form>
    </div>
  );
}

export default ApplyLeave;