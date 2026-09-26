import mongoose from "mongoose";

const leaveSchema = new mongoose.Schema(
  {
    employee: {type: mongoose.Schema.Types.ObjectId,  ref: "Auth",  required: true,},
    leaveType: {type: String,enum: ["CL", "SL", "EL", "PL"],required: true, },
    startDate: {type: Date,required: true,},
    endDate: {type: Date,required: true,},
    totalDays: { type: Number, required: true,},
    reason: {type: String,required: true},
    status: { type: String,enum: ["Pending", "Approved", "Rejected"],default: "Pending",},
    approvedBy: {type: mongoose.Schema.Types.ObjectId,ref: "Auth",default: null,},
  },
  {
    timestamps: true,
  }
);

export default mongoose.model("Leave", leaveSchema);