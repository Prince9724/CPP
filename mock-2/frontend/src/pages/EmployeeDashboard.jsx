import { useEffect, useState } from "react";
import { Link } from "react-router-dom";
import api from "../services/api";

function EmployeeDashboard() {
  const [leaves, setLeaves] = useState([]);
  const [loading, setLoading] = useState(true);

  const user = JSON.parse(localStorage.getItem("user"));

  const getMyLeaves = async () => {
    try {
      const response = await api.get("/leaves/my");

      setLeaves(response.data.leaves || []);
    } catch (error) {
      console.log(error);

      alert(
        error.response?.data?.message ||
          "Failed to load dashboard"
      );
    } finally {
      setLoading(false);
    }
  };

  useEffect(() => {
    getMyLeaves();
  }, []);

  // Real calculations
  const totalRequests = leaves.length;

  const approvedLeaves = leaves.filter(
    (leave) => leave.status === "Approved"
  );

  const pendingLeaves = leaves.filter(
    (leave) => leave.status === "Pending"
  );

  const rejectedLeaves = leaves.filter(
    (leave) => leave.status === "Rejected"
  );

  const usedLeaves = approvedLeaves.reduce(
    (total, leave) => total + leave.totalDays,
    0
  );

  // Example yearly total
  const totalLeaveBalance = 27;

  const remainingLeaves =
    totalLeaveBalance - usedLeaves;

  // Recent 5 requests
  const recentLeaves = leaves.slice(0, 5);

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
        <h2>Loading dashboard...</h2>
      </div>
    );
  }

  return (
    <div className="container py-4">

      {/* Header */}
      <div className="mb-4">
        <h1 className="fw-bold">Employee Dashboard</h1>
        <h4 className="mb-1">
          Welcome, {user?.name}
        </h4>
        <p className="text-muted mb-0">
          {user?.email}
        </p>
      </div>

      {/* Statistics */}
      <div className="row g-3 mb-4">

        <div className="col-md-3">
          <div className="card shadow-sm h-100">
            <div className="card-body">
              <h6 className="text-muted">
                Total Leave Balance
              </h6>
              <h2 className="fw-bold">
                {totalLeaveBalance}
              </h2>
            </div>
          </div>
        </div>

        <div className="col-md-3">
          <div className="card shadow-sm h-100">
            <div className="card-body">
              <h6 className="text-muted">
                Used Leaves
              </h6>
              <h2 className="fw-bold">
                {usedLeaves}
              </h2>
            </div>
          </div>
        </div>

        <div className="col-md-3">
          <div className="card shadow-sm h-100">
            <div className="card-body">
              <h6 className="text-muted">
                Remaining Leaves
              </h6>
              <h2 className="fw-bold">
                {remainingLeaves}
              </h2>
            </div>
          </div>
        </div>

        <div className="col-md-3">
          <div className="card shadow-sm h-100">
            <div className="card-body">
              <h6 className="text-muted">
                Pending Requests
              </h6>
              <h2 className="fw-bold">
                {pendingLeaves.length}
              </h2>
            </div>
          </div>
        </div>

      </div>

      {/* Request Statistics */}
      <div className="card shadow-sm mb-4">
        <div className="card-body">

          <h4 className="mb-4">
            Leave Request Summary
          </h4>

          <div className="row text-center">

            <div className="col-md-3">
              <h5>{totalRequests}</h5>
              <p className="text-muted">
                Total Requests
              </p>
            </div>

            <div className="col-md-3">
              <h5>{approvedLeaves.length}</h5>
              <p className="text-success">
                Approved
              </p>
            </div>

            <div className="col-md-3">
              <h5>{pendingLeaves.length}</h5>
              <p className="text-warning">
                Pending
              </p>
            </div>

            <div className="col-md-3">
              <h5>{rejectedLeaves.length}</h5>
              <p className="text-danger">
                Rejected
              </p>
            </div>

          </div>

        </div>
      </div>

      {/* Quick Actions */}
      <div className="card shadow-sm mb-4">
        <div className="card-body">

          <h4 className="mb-3">
            Quick Actions
          </h4>

          <div className="d-flex gap-2 flex-wrap">

            <Link
              to="/employee/apply-leave"
              className="btn btn-primary"
            >
              Apply Leave
            </Link>

            <Link
              to="/employee/history"
              className="btn btn-outline-primary"
            >
              View Leave History
            </Link>

            <Link
              to="/employee/balance"
              className="btn btn-outline-secondary"
            >
              View Leave Balance
            </Link>

          </div>

        </div>
      </div>

      {/* Recent Requests */}
      <div className="card shadow-sm">

        <div className="card-body">

          <h4 className="mb-4">
            Recent Leave Requests
          </h4>

          {recentLeaves.length === 0 ? (
            <p className="text-muted">
              You have not applied for any leave yet.
            </p>
          ) : (
            <div className="table-responsive">

              <table className="table table-bordered table-hover align-middle">

                <thead className="table-light">
                  <tr>
                    <th>Leave Type</th>
                    <th>From</th>
                    <th>To</th>
                    <th>Total Days</th>
                    <th>Reason</th>
                    <th>Status</th>
                  </tr>
                </thead>

                <tbody>

                  {recentLeaves.map((leave) => (
                    <tr key={leave._id}>

                      <td>
                        <strong>
                          {leave.leaveType}
                        </strong>
                      </td>

                      <td>
                        {formatDate(leave.startDate)}
                      </td>

                      <td>
                        {formatDate(leave.endDate)}
                      </td>

                      <td>
                        {leave.totalDays}
                      </td>

                      <td>
                        {leave.reason}
                      </td>

                      <td>
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
                      </td>

                    </tr>
                  ))}

                </tbody>

              </table>

            </div>
          )}

        </div>

      </div>

    </div>
  );
}

export default EmployeeDashboard;