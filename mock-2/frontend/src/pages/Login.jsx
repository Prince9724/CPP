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
      const response = await api.post("/auth/login", { email,password,});
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
    <div className="login-page">

      <div className="login-box">

        <h1>LeavePro</h1>

        <p>Employee Leave Management System</p>

        <form onSubmit={handleLogin}>

          <input type="email"placeholder="Email"value={email}onChange={(e) => setEmail(e.target.value)}/>

          <input type="password"placeholder="Password"value={password}onChange={(e) => setPassword(e.target.value)}/>
          <button type="submit">
            Login
          </button>

        </form>

      </div>

    </div>
  );
}

export default Login;