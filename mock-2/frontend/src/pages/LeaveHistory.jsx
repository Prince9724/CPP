import { useEffect, useState } from "react";
import api from "../services/api";

function LeaveHistory() {
  const [leaves, setLeaves] = useState([]);
  const [loading, setLoading] = useState(true);

  const getMyLeaves = async () => {
    try {
      const response = await api.get("/leaves/my");

      setLeaves(response.data.leaves || []);
    } catch (error) {
      console.log(error);
    } finally {
      setLoading(false);
    }
  };

  useEffect(() => {
    getMyLeaves();
  }, []);

  const formatDate = (date) => {
    return new Date(date).toLocaleDateString("en-IN", {
      day: "2-digit",
      month: "short",
      year: "numeric",
    });
  };

  if (loading) {
    return (
      <div className="container mt-5 text-center">
        <h4>Loading...</h4>
      </div>
    );
  }

  return (
    <div className="container py-4">

      <div className="mb-4">
        <h1 className="fw-bold">My Leave History</h1>
        <p className="text-muted">
          View all your leave requests and their status.
        </p>
      </div>

      {leaves.length === 0 ? (
        <div className="alert alert-info">
          No leave requests found.
        </div>
      ) : (
        <div className="row g-4">

          {leaves.map((leave) => (
            <div
              className="col-md-6"
              key={leave._id}
            >
              <div className="card shadow-sm h-100">

                <div className="card-body">

                  <div className="d-flex justify-content-between align-items-center mb-3">

                    <h4 className="mb-0">
                      {leave.leaveType}
                    </h4>

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

                  <p className="mb-2">
                    <strong>Start Date:</strong>{" "}
                    {formatDate(leave.startDate)}
                  </p>

                  <p className="mb-2">
                    <strong>End Date:</strong>{" "}
                    {formatDate(leave.endDate)}
                  </p>

                  <p className="mb-2">
                    <strong>Total Days:</strong>{" "}
                    {leave.totalDays}
                  </p>

                  <p className="mb-0">
                    <strong>Reason:</strong>{" "}
                    {leave.reason}
                  </p>

                </div>

              </div>
            </div>
          ))}

        </div>
      )}

    </div>
  );
}

export default LeaveHistory;