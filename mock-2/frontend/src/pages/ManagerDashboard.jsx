import { useEffect, useState } from "react";
import api from "../services/api";

function ManagerDashboard() {
  const [leaves, setLeaves] = useState([]);

  const getLeaves = async () => {
    try {
      const response = await api.get("/leaves");

      setLeaves(response.data.leaves || []);
    } catch (error) {
      console.log(error);

      alert(
        error.response?.data?.message ||
          "Failed to load leave requests"
      );
    }
  };

  useEffect(() => {
    getLeaves();
  }, []);

  const approveLeave = async (id) => {
    try {
      await api.put(`/leaves/${id}/approve`);

      alert("Leave approved");

      getLeaves();
    } catch (error) {
      alert(
        error.response?.data?.message ||
          "Approval failed"
      );
    }
  };

  const rejectLeave = async (id) => {
    try {
      await api.put(`/leaves/${id}/reject`);

      alert("Leave rejected");

      getLeaves();
    } catch (error) {
      alert(
        error.response?.data?.message ||
          "Rejection failed"
      );
    }
  };

  return (
    <div className="container py-4">

      {/* Header */}
      <div className="mb-4">
        <h1 className="fw-bold">
          Manager Dashboard
        </h1>

        <p className="text-muted">
          Manage employee leave requests
        </p>
      </div>

      {/* Leave Requests */}
      <div className="card shadow-sm">

        <div className="card-header">
          <h4 className="mb-0">
            Leave Requests
          </h4>
        </div>

        <div className="card-body">

          {leaves.length === 0 ? (
            <div className="alert alert-info mb-0">
              No leave requests found.
            </div>
          ) : (
            <div className="row g-4">

              {leaves.map((leave) => (
                <div
                  className="col-md-6"
                  key={leave._id}
                >

                  <div className="card border h-100">

                    <div className="card-body">

                      {/* Employee */}
                      <h4 className="mb-1">
                        {leave.employee?.name}
                      </h4>

                      <p className="text-muted">
                        {leave.employee?.email}
                      </p>

                      <hr />

                      <p className="mb-2">
                        <strong>Leave Type:</strong>{" "}
                        {leave.leaveType}
                      </p>

                      <p className="mb-2">
                        <strong>Start Date:</strong>{" "}
                        {leave.startDate}
                      </p>

                      <p className="mb-2">
                        <strong>End Date:</strong>{" "}
                        {leave.endDate}
                      </p>

                      <p className="mb-2">
                        <strong>Total Days:</strong>{" "}
                        {leave.totalDays}
                      </p>

                      <p className="mb-3">
                        <strong>Reason:</strong>{" "}
                        {leave.reason}
                      </p>

                      {/* Status */}
                      <p>
                        <strong>Status:</strong>{" "}

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
                      </p>

                      {/* Buttons */}
                      {leave.status === "Pending" && (
                        <div className="d-flex gap-2 mt-3">

                          <button
                            className="btn btn-success"
                            onClick={() =>
                              approveLeave(leave._id)
                            }
                          >
                            Approve
                          </button>

                          <button
                            className="btn btn-danger"
                            onClick={() =>
                              rejectLeave(leave._id)
                            }
                          >
                            Reject
                          </button>

                        </div>
                      )}

                    </div>

                  </div>

                </div>
              ))}

            </div>
          )}

        </div>

      </div>

    </div>
  );
}

export default ManagerDashboard;