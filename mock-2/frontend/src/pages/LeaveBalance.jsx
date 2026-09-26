import { useEffect, useState } from "react";
import api from "../services/api";

function LeaveBalance() {
  const [leaves, setLeaves] = useState([]);

  const leaveLimits = {
    CL: 12,
    SL: 8,
    EL: 5,
    PL: 2,
  };

  useEffect(() => {
    const getLeaves = async () => {
      try {
        const response = await api.get("/leaves/my");

        setLeaves(response.data.leaves || []);
      } catch (error) {
        console.log(error);
      }
    };

    getLeaves();
  }, []);

  const getUsedDays = (type) => {
    return leaves
      .filter(
        (leave) =>
          leave.leaveType === type &&
          leave.status === "Approved"
      )
      .reduce(
        (total, leave) => total + leave.totalDays,
        0
      );
  };

  return (
    <div>
      <h1>My Leave Balance</h1>

      {Object.entries(leaveLimits).map(
        ([type, limit]) => {
          const used = getUsedDays(type);
          const remaining = Math.max(
            limit - used,
            0
          );

          return (
            <div key={type}>

              <h2>{type}</h2>

              <p>
                Total: {limit}
              </p>

              <p>
                Used: {used}
              </p>

              <p>
                Remaining: {remaining}
              </p>

              <hr />

            </div>
          );
        }
      )}
    </div>
  );
}

export default LeaveBalance;