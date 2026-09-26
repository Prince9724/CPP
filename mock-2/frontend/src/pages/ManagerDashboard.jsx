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
    <div>
      <h1>Manager Dashboard</h1>

      <h2>Leave Requests</h2>

      {leaves.length === 0 ? (
        <p>No leave requests found.</p>
      ) : (
        leaves.map((leave) => (
          <div key={leave._id}>

            <h3>
              {leave.employee?.name}
            </h3>

            <p>
              Email: {leave.employee?.email}
            </p>

            <p>
              Leave Type: {leave.leaveType}
            </p>

            <p>
              Start Date: {leave.startDate}
            </p>

            <p>
              End Date: {leave.endDate}
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

            {leave.status === "Pending" && (
              <>
                <button
                  onClick={() => approveLeave(leave._id)}
                >
                  Approve
                </button>

                <button
                  onClick={() => rejectLeave(leave._id)}
                >
                  Reject
                </button>
              </>
            )}

            <hr />
          </div>
        ))
      )}
    </div>
  );
}

export default ManagerDashboard;