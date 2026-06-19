import express from "express";
import type { Request, Response } from "express";
import dotenv from "dotenv";
import { FileLogger } from "./logger/infra/logger.js";

dotenv.config();
const app = express();
const PORT = process.env.PORT;

const logger = new FileLogger();
logger.info("Logger initialized successfully.");

// Middleware to parse JSON bodies
app.use(express.json());
app.use(express.urlencoded({ extended: true }));

// Basic Route
app.get("/", (req: Request, res: Response) => {
  res.json({ message: "Hello from Express + TypeScript + pnpm!" });
});

// Start Server
app.listen(PORT, () => {
  logger.info(`🚀 Server is running on http://localhost:${PORT}`);
});
