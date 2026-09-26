// import { BrowserRouter, Routes, Route } from "react-router-dom";

// import Login from "./pages/Login";
// import EmployeeDashboard from "./pages/EmployeeDashboard";
// // import ApplyLeave from "./pages/ApplyLeave";
// // import LeaveHistory from "./pages/LeaveHistory";
// // import LeaveBalance from "./pages/LeaveBalance";
// // import ManagerDashboard from "./pages/ManagerDashboard";

// function App() {
//   return (
//     <BrowserRouter>
//       <Routes>
//         <Route path="/" element={<Login />} />
//         <Route path="/employee/dashboard" element={<EmployeeDashboard />}/>
//         <Route path="/employee/apply-leave"element={<ApplyLeave />}/>
//         <Route path="/employee/history"element={<LeaveHistory />}/>
//         <Route path="/employee/balance"element={<LeaveBalance />}/>
//         <Route path="/manager/dashboard"element={<ManagerDashboard />}/>
//       </Routes>
//     </BrowserRouter>
//   );
// }

// export default App;

import {
  BrowserRouter,
  Routes,
  Route,
} from "react-router-dom";

import Login from "./pages/Login";
import Register from "./pages/Register";

import EmployeeDashboard from "./pages/EmployeeDashboard";
import ApplyLeave from "./pages/ApplyLeave";
import LeaveHistory from "./pages/LeaveHistory";
import LeaveBalance from "./pages/LeaveBalance";

import ManagerDashboard from "./pages/ManagerDashboard";
import LeaveDetails from "./pages/LeaveDetails";

function App() {
  return (
    <BrowserRouter>
      <Routes>

        {/* Authentication */}

        <Route
          path="/login"
          element={<Login />}
        />

        <Route
          path="/"
          element={<Register />}
        />


        {/* Employee */}

        <Route
          path="/employee/dashboard"
          element={<EmployeeDashboard />}
        />

        <Route
          path="/employee/apply-leave"
          element={<ApplyLeave />}
        />

        <Route
          path="/employee/history"
          element={<LeaveHistory />}
        />

        <Route
          path="/employee/balance"
          element={<LeaveBalance />}
        />


        {/* Manager */}

        <Route
          path="/manager/dashboard"
          element={<ManagerDashboard />}
        />

        <Route
          path="/manager/leave/:id"
          element={<LeaveDetails />}
        />

      </Routes>
    </BrowserRouter>
  );
}

export default App;