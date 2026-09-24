import mongoose from "mongoose";

const authModel = new mongoose.Schema({
    name :{type:string, required:true},
    email:{type:string, required:true, unique:true},
    password:{type:string, required:true}
})

export default mongoose.model("Auth",authModel);