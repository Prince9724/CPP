import { useEffect, useState } from "react";
import { useParams } from "react-router-dom";
import api from "../services/api";

function LeaveDetails() {
  const { id } = useParams();

  const [leave, setLeave] = useState(null);

  const getLeave = async () => {
    try {
      const response = await api.get(`/leaves/${id}`);

      setLeave(response.data);
    } catch (error) {
      console.log(error);
    }
  };

  useEffect(() => {
    getLeave();
  }, []);

  if (!leave) {
    return (
      <div className="container mt-5 text-center">
        <h4>Loading...</h4>
      </div>
    );
  }

  return (
    <div className="container py-4">

      <div className="row justify-content-center">

        <div className="col-md-7">

          <div className="card shadow-sm">

            <div className="card-header">
              <h3 className="mb-0">Leave Details</h3>
            </div>

            <div className="card-body">

              <div className="mb-3">
                <strong>Employee:</strong>
                <p className="mb-0">
                  {leave.employee?.name}
                </p>
              </div>

              <div className="mb-3">
                <strong>Email:</strong>
                <p className="mb-0">
                  {leave.employee?.email}
                </p>
              </div>

              <div className="mb-3">
                <strong>Leave Type:</strong>
                <p className="mb-0">
                  {leave.leaveType}
                </p>
              </div>

              <div className="mb-3">
                <strong>Start Date:</strong>
                <p className="mb-0">
                  {leave.startDate}
                </p>
              </div>

              <div className="mb-3">
                <strong>End Date:</strong>
                <p className="mb-0">
                  {leave.endDate}
                </p>
              </div>

              <div className="mb-3">
                <strong>Total Days:</strong>
                <p className="mb-0">
                  {leave.totalDays}
                </p>
              </div>

              <div className="mb-3">
                <strong>Reason:</strong>
                <p className="mb-0">
                  {leave.reason}
                </p>
              </div>

              <div>
                <strong>Status:</strong>
                <div className="mt-1">
                  <span
                    className={`badge ${
                      leave.status === "Approved"
                        ? "text-bg-success"
                        : leave.status === "Rejected"
                        ? "text-bg-danger"
                        : "text-bg-warning"
                    }`}
                  >
                    {leave.status}
                  </span>
                </div>
              </div>

            </div>

          </div>

        </div>

      </div>

    </div>
  );
}

export default LeaveDetails;