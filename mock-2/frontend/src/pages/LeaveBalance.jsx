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
    <div className="container py-4">

      {/* Header */}
      <div className="mb-4">
        <h1 className="fw-bold">My Leave Balance</h1>
        <p className="text-muted">
          Check your total, used and remaining leaves.
        </p>
      </div>

      {/* Leave Cards */}
      <div className="row g-4">

        {Object.entries(leaveLimits).map(
          ([type, limit]) => {
            const used = getUsedDays(type);
            const remaining = Math.max(
              limit - used,
              0
            );

            return (
              <div
                className="col-md-6 col-lg-3"
                key={type}
              >
                <div className="card shadow-sm h-100">

                  <div className="card-body">

                    <h3 className="fw-bold mb-3">
                      {type}
                    </h3>

                    <div className="mb-2">
                      <span className="text-muted">
                        Total
                      </span>
                      <h5>{limit}</h5>
                    </div>

                    <div className="mb-2">
                      <span className="text-muted">
                        Used
                      </span>
                      <h5>{used}</h5>
                    </div>

                    <div>
                      <span className="text-muted">
                        Remaining
                      </span>
                      <h5 className="text-success">
                        {remaining}
                      </h5>
                    </div>

                  </div>

                </div>
              </div>
            );
          }
        )}

      </div>
    </div>
  );
}

export default LeaveBalance;