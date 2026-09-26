import Leave from "../models/Leave.js";

export const applyLeave = async (req, res) => {
  try {
    const { leaveType,startDate, endDate,reason,} = req.body;

    if (!leaveType || !startDate || !endDate || !reason) {
      return res.status(400).json({
        message: "All fields are required",
      });
    }

    const start = new Date(startDate);
    const end = new Date(endDate);

    if (end < start) {
      return res.status(400).json({
        message: "End date cannot be before start date", 
    });
    }

    const totalDays = Math.ceil((end - start) / (1000 * 60 * 60 * 24)) + 1;
    const leave = await Leave.create({employee: req.user.id,leaveType, startDate, endDate, totalDays,reason,});

    res.status(201).json({
      message: "Leave applied successfully",
      leave,
    });
  } catch (error) {
    res.status(500).json({
      message: "Leave application failed",
      error: error.message,
    });
  }
};
export const getAllLeaves = async (req, res) => {
  try {
    const leaves = await Leave.find()
      .populate("employee", "name email role")
      .populate("approvedBy", "name email");

    res.status(200).json({
      message: "All leave requests",
      leaves,
    });
  } catch (error) {
    res.status(500).json({
      message: "Failed to get leaves",
      error: error.message,
    });
  }
};
export const getLeaveById = async (req, res) => {
  try {
    const leave = await Leave.findById(req.params.id)
      .populate("employee", "name email role")
      .populate("approvedBy", "name email");

    if (!leave) {
      return res.status(404).json({
        message: "Leave not found",
      });
    }

    res.status(200).json(leave);
  } catch (error) {
    res.status(500).json({
      message: "Failed to get leave",
      error: error.message,
    });
  }
};
export const approveLeave = async (req, res) => {
  try {
    const leave = await Leave.findById(req.params.id);

    if (!leave) {
      return res.status(404).json({
        message: "Leave not found",
      });
    }

    leave.status = "Approved";
    leave.approvedBy = req.user.id;

    await leave.save();

    res.status(200).json({
      message: "Leave approved successfully",
      leave,
    });
  } catch (error) {
    res.status(500).json({
      message: "Failed to approve leave",
      error: error.message,
    });
  }
};export const rejectLeave = async (req, res) => {
  try {
    const leave = await Leave.findById(req.params.id);

    if (!leave) {
      return res.status(404).json({
        message: "Leave not found",
      });
    }

    leave.status = "Rejected";
    leave.approvedBy = req.user.id;

    await leave.save();

    res.status(200).json({
      message: "Leave rejected successfully",
      leave,
    });
  } catch (error) {
    res.status(500).json({
      message: "Failed to reject leave",
      error: error.message,
    });
  }
};
export const getMyLeaves = async (req, res) => {
  try {
    const leaves = await Leave.find({
      employee: req.user.id,
    })
      .populate("employee", "name email role")
      .sort({ createdAt: -1 });

    res.status(200).json({
      message: "My leave requests",
      leaves,
    });
  } catch (error) {
    res.status(500).json({
      message: "Failed to get your leaves",
      error: error.message,
    });
  }
};
