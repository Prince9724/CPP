import express from "express";

import { applyLeave,getMyLeaves ,getAllLeaves,getLeaveById ,approveLeave, rejectLeave } from "../controllers/leaveController.js";

import { authMiddleware } from "../middlewares/authMiddleware.js";

import { roleMiddleware } from "../middlewares/roleMiddleware.js";

const router = express.Router();
router.post( "/",authMiddleware, roleMiddleware("employee"),applyLeave);


// Manager
router.get("/", authMiddleware, roleMiddleware("manager"), getAllLeaves);
// Keep this specific employee route before /:id so "my" is not treated as an ID.
router.get("/my", authMiddleware, roleMiddleware("employee"), getMyLeaves);
router.get("/:id",authMiddleware,roleMiddleware("manager"),getLeaveById);
router.put("/:id/approve",authMiddleware,roleMiddleware("manager"),approveLeave);
router.put("/:id/reject",authMiddleware, roleMiddleware("manager"),rejectLeave);
export default router;