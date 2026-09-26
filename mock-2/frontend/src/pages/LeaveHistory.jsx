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
    return <h2>Loading...</h2>;
  }

  return (
    <div>
      <h1>My Leave History</h1>

      {leaves.length === 0 ? (
        <p>No leave requests found.</p>
      ) : (
        leaves.map((leave) => (
          <div key={leave._id}>

            <p>
              Leave Type: {leave.leaveType}
            </p>

            <p>
              Start Date: {formatDate(leave.startDate)}
            </p>

            <p>
              End Date: {formatDate(leave.endDate)}
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
  );
}

export default LeaveHistory;