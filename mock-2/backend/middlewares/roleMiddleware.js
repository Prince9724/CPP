export const roleMiddleware = (...roles) => {
  return (req, res, next) => {

    console.log("JWT USER:", req.user);
    console.log("USER ROLE:", req.user?.role);
    console.log("ALLOWED ROLES:", roles);

    if (!req.user) {
      return res.status(401).json({
        message: "Not authenticated",
      });
    }

    if (!roles.includes(req.user.role)) {
      return res.status(403).json({
        message: `Access denied. Your role is ${req.user.role}`,
      });
    }

    next();
  };
};