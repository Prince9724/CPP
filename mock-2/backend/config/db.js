import mongoose from "mongoose";

const connectdb = async () => {
    try {
        await mongoose.connect("mongodb://princegondrw123_db_user:ye8pLlDGed55fOod@ac-oneltwz-shard-00-00.xauzrni.mongodb.net:27017,ac-oneltwz-shard-00-01.xauzrni.mongodb.net:27017,ac-oneltwz-shard-00-02.xauzrni.mongodb.net:27017/mock?ssl=true&replicaSet=atlas-vmr5og-shard-0&authSource=admin&appName=mock");

        console.log("MongoDB connected successfully!");
    } catch (err) {
        console.log("MongoDB connection failed!", err);
    }
};

export default connectdb;