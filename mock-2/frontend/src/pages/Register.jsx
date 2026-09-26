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
    <div>
      <h1>LeavePro</h1>

      <h2>Create Account</h2>

      <form onSubmit={handleSubmit}>

        <div>
          <label>Name</label>

          <input
            type="text"
            name="name"
            placeholder="Enter your name"
            value={form.name}
            onChange={handleChange}
            required
          />
        </div>

        <br />

        <div>
          <label>Email</label>

          <input
            type="email"
            name="email"
            placeholder="Enter your email"
            value={form.email}
            onChange={handleChange}
            required
          />
        </div>

        <br />

        <div>
          <label>Password</label>

          <input
            type="password"
            name="password"
            placeholder="Enter password"
            value={form.password}
            onChange={handleChange}
            required
          />
        </div>

        <br />

        <div>
          <label>Role</label>

          <select
            name="role"
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

        <br />

        <button type="submit">
          Register
        </button>

      </form>

       
        <button onClick={() => navigate("/login")}>
         Already have an account?
      </button>
      <button onClick={() => navigate("/login")}>
        Login
      </button>
    </div>
  );
}

export default Register;