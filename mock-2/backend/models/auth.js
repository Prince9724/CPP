import mongoose from "mongoose";

const AuthSchema = new mongoose.Schema(
  {
    name:{type: String,required: true},
    email:{type: String,required: true,unique: true,},password:{type: String, required: true,},
     role:{type: String, required: true, enum: ["employee", "manager"],default: "employee", },
      password: { type: String, required: true,},
    },
     
  {
    timestamps: true,
  }
);

export default mongoose.model("Auth", AuthSchema);