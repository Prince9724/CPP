import { useState } from "react";
import { useNavigate } from "react-router-dom";
import api from "../services/api";

function Login() {
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");

  const navigate = useNavigate();

  const handleLogin = async (e) => {
    e.preventDefault();

    try {
      const response = await api.post("/auth/login", {
        email,
        password,
      });

      const user = response.data.user;

      localStorage.setItem("user", JSON.stringify(user));

      if (user.role === "manager") {
        navigate("/manager/dashboard");
      } else {
        navigate("/employee/dashboard");
      }
    } catch (error) {
      console.log(error);

      alert(
        error.response?.data?.message || "Login failed"
      );
    }
  };

  return (
    <div className="container">
      <div className="row justify-content-center align-items-center min-vh-100">

        <div className="col-md-5">

          <div className="card shadow">

            <div className="card-body p-4">

              <h2 className="text-center mb-2">
                LeavePro
              </h2>

              <p className="text-center text-muted mb-4">
                Employee Leave Management System
              </p>

              <form onSubmit={handleLogin}>

                <div className="mb-3">
                  <label className="form-label">
                    Email
                  </label>

                  <input
                    type="email"
                    className="form-control"
                    placeholder="Enter your email"
                    value={email}
                    onChange={(e) =>
                      setEmail(e.target.value)
                    }
                    required
                  />
                </div>

                <div className="mb-3">
                  <label className="form-label">
                    Password
                  </label>

                  <input
                    type="password"
                    className="form-control"
                    placeholder="Enter your password"
                    value={password}
                    onChange={(e) =>
                      setPassword(e.target.value)
                    }
                    required
                  />
                </div>

                <button
                  type="submit"
                  className="btn btn-primary w-100"
                >
                  Login
                </button>

              </form>

              <div className="text-center mt-3">
                <span className="text-muted">
                  Don't have an account?
                </span>

                <button
                  className="btn btn-link"
                  onClick={() => navigate("/")}
                >
                  Register
                </button>
              </div>

            </div>

          </div>

        </div>

      </div>
    </div>
  );
}

export default Login;