import express from "express";
import cors from "cors";
import cookieParser from "cookie-parser";
import dotenv from "dotenv";

import connectdb from "./config/db.js";
import router from "./routes/authRoute.js";
import leaveRoute from "./routes/leaveRoute.js"
dotenv.config();
const app = express();
connectdb();

app.use(express.json());
app.use(
  cors({
    origin: "http://localhost:5173",
    credentials: true,
  })
);
app.use(cookieParser());

app.use("/api/auth", router);
app.use("/api/leaves", leaveRoute);
app.get("/", (req, res) => { res.json({ message: "LeavePro Backend Runing",});
});
const PORT = process.env.PORT || 5000;
app.listen(PORT, () => {
  console.log(`Server running on port ${PORT}`);
});