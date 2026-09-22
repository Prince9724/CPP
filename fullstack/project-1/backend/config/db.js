import mongoose from"mongoose"

const connectdb = async(req , res )=>{
    try{    
        const result = mongoose.connect("mongodb://127.0.0.1:27017/project1")
        console.log("mongd connected successfully !! ");

    }
    catch(err){
        console.log("mongodb connection failed !! " , err);
    }
}

export default connectdb ; 