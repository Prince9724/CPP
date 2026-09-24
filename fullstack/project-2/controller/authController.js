import user from "../models/authModel.js";
import bcrypt from "bcrypt";


export const signUp = async(req, res)=>{
        try{
            const {email, name , password}= req.body ;  
            const hash = bcrypt.hash(password , 12);

            
        }
        catch(err){
            res.json({
            status:false,
            message:"mongodb connection failled !! ",
            err : err.message
        })
        }
}