import user from "../models/authModel.js"
import bcrypt from "bcrypt"
export const signUp= async(req , res)=>{
   try{
      const password = req.body.password ; 
    const hash = bcrypt.hash(password , 10);

     const result = await user.create({...req.body,password :hash});
    res.json({
        status:true,
        message:"user signUp succesfully !! ",
        data :result
    })
   }
   catch(err){
     res.json({
        status:false , 
        message:" user signUp failed !! ",
        err :err.message
     })
   }
}


export const signIn = async (req, res )=>{

    try{
        const {email, password} = req.body
        const userData =  await user.find({email});
        if(!userData){
            return res.json({
                status:false ,
                message :"user not found !! "
            })
        }
        const isMatch = await bcrypt.compare(password , userData.password);

    }
    catch(err){

    }
}
