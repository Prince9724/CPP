import mongoose  from "mongoose";

const AuthSchema = new mongoose.Schema({
    name:{type:String , required:true},
    email:{type:String,required : true, unique:true},
    password:{type:String , required:true},
    age:{type:Number},
    salary:{type:Number}
})

export default mongoose.model("Auth", AuthSchema);