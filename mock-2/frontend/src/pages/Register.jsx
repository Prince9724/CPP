import { useState } from "react";
import { useNavigate } from "react-router-dom";
import api from "../services/api";

function Register() {
  const navigate = useNavigate();

  const [form, setForm] = useState({
    name: "",
    email: "",
    password: "",
    role: "employee",
  });

  const handleChange = (e) => {
    setForm({
      ...form,
      [e.target.name]: e.target.value,
    });
  };

  const handleSubmit = async (e) => {
    e.preventDefault();

    try {
      const response = await api.post("/auth/register", form);

      alert(response.data.message);

      navigate("/");
    } catch (error) {
      console.log(error);

      alert(
        error.response?.data?.message ||
          "Registration failed"
      );
    }
  };

  return (
    <div className="container">
      <div className="row justify-content-center align-items-center min-vh-100">

        <div className="col-md-5">

          <div className="card shadow-sm">

            <div className="card-body p-4">

              <h1 className="text-center mb-2">
                LeavePro
              </h1>

              <h4 className="text-center text-muted mb-4">
                Create Account
              </h4>

              <form onSubmit={handleSubmit}>

                {/* Name */}
                <div className="mb-3">
                  <label className="form-label">
                    Name
                  </label>

                  <input
                    type="text"
                    name="name"
                    className="form-control"
                    placeholder="Enter your name"
                    value={form.name}
                    onChange={handleChange}
                    required
                  />
                </div>

                {/* Email */}
                <div className="mb-3">
                  <label className="form-label">
                    Email
                  </label>

                  <input
                    type="email"
                    name="email"
                    className="form-control"
                    placeholder="Enter your email"
                    value={form.email}
                    onChange={handleChange}
                    required
                  />
                </div>

                {/* Password */}
                <div className="mb-3">
                  <label className="form-label">
                    Password
                  </label>

                  <input
                    type="password"
                    name="password"
                    className="form-control"
                    placeholder="Enter password"
                    value={form.password}
                    onChange={handleChange}
                    required
                  />
                </div>

                {/* Role */}
                <div className="mb-4">
                  <label className="form-label">
                    Role
                  </label>

                  <select
                    name="role"
                    className="form-select"
                    value={form.role}
                    onChange={handleChange}
                  >
                    <option value="employee">
                      Employee
                    </option>

                    <option value="manager">
                      Manager
                    </option>
                  </select>
                </div>

                {/* Register */}
                <button
                  type="submit"
                  className="btn btn-primary w-100"
                >
                  Register
                </button>

              </form>

              <div className="text-center mt-4">

                <p className="mb-2 text-muted">
                  Already have an account?
                </p>

                <button
                  className="btn btn-outline-primary"
                  onClick={() => navigate("/login")}
                >
                  Login
                </button>

              </div>

            </div>

          </div>

        </div>

      </div>
    </div>
  );
}

export default Register;