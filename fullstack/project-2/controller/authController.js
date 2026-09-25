import user from "../models/authModel.js";
import bcrypt from "bcrypt";


export const signUp = async(req, res)=>{
        try{
            const {email, name , password}= req.body ;  
            const hash = bcrypt.hash(password , 12);
            const result = await user.create();
            res.json({
               status:true,
               message:"signup succesfully !! ",
               result 
            })

        }
        catch(err){
            res.json({
            status:false,
            message:"signup  failled !! ",
            err : err.message
        })
        }
}
export const signIn = async (req , res )=>{
    try{
        const {email, password , name } =  req.body ; 

        const result = await user.find({email});
        if(!result){
            res.json({
                status:false,
                message:"user not found !! ",
                err :err.message
            })
        }
        const isMatch =  await bcrypt.compare(password , user,password);

    }
    catch(err){
        res.json({
            status:false,
            message:"signIn  failled !! ",
            err : err.message
        })
    }


}