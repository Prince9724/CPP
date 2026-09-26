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
    return <p>Loading...</p>;
  }

  return (
    <div>
      <h1>Leave Details</h1>

      <p>
        Employee: {leave.employee?.name}
      </p>

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
    </div>
  );
}

export default LeaveDetails;