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
    return <h2>Loading dashboard...</h2>;
  }

  return (
    <div>

      {/* Header */}

      <h1>Employee Dashboard</h1>

      <h2>
        Welcome, {user?.name}
      </h2>

      <p>
        {user?.email}
      </p>


      {/* Statistics */}

      <div>

        <div>
          <h3>Total Leave Balance</h3>
          <h2>{totalLeaveBalance}</h2>
        </div>

        <div>
          <h3>Used Leaves</h3>
          <h2>{usedLeaves}</h2>
        </div>

        <div>
          <h3>Remaining Leaves</h3>
          <h2>{remainingLeaves}</h2>
        </div>

        <div>
          <h3>Pending Requests</h3>
          <h2>{pendingLeaves.length}</h2>
        </div>

      </div>


      {/* Request Statistics */}

      <div>

        <h2>Leave Request Summary</h2>

        <p>
          Total Requests: {totalRequests}
        </p>

        <p>
          Approved: {approvedLeaves.length}
        </p>

        <p>
          Pending: {pendingLeaves.length}
        </p>

        <p>
          Rejected: {rejectedLeaves.length}
        </p>

      </div>


      {/* Quick Actions */}

      <div>

        <h2>Quick Actions</h2>

        <Link to="/employee/apply-leave">
          Apply Leave
        </Link>

        <br />

        <Link to="/employee/history">
          View Leave History
        </Link>

        <br />

        <Link to="/employee/balance">
          View Leave Balance
        </Link>

      </div>


      {/* Recent Requests */}

      <div>

        <h2>Recent Leave Requests</h2>

        {recentLeaves.length === 0 ? (
          <p>
            You have not applied for any leave yet.
          </p>
        ) : (
          recentLeaves.map((leave) => (
            <div key={leave._id}>

              <h3>
                {leave.leaveType}
              </h3>

              <p>
                From: {formatDate(leave.startDate)}
              </p>

              <p>
                To: {formatDate(leave.endDate)}
              </p>

              <p>
                Total Days: {leave.totalDays}
              </p>

              <p>
                Reason: {leave.reason}
              </p>

              <p>
                Status: {leave.status}
              </p>

              <hr />

            </div>
          ))
        )}

      </div>

    </div>
  );
}

export default EmployeeDashboard;