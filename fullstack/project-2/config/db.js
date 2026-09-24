import mongoose from "mongoose";

const connectdb = async ()=>{
   
    try{
        mongoose.connect("mongodb://127.0.0.1:27017/project2");
        console.log("mongodb connected succesfully !! ")
    }
    catch(err){
        console.log("mongodb connection failed !! ");
    }
}

export default connectdb;