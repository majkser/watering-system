import type { Logger } from "../core/logger.js";
import {
  createLogger,
  format,
  transports,
  type Logger as WinstonLogger,
} from "winston";
import DailyRotateFile from "winston-daily-rotate-file";
import path from "path";

export class FileLogger implements Logger {
  private logger: WinstonLogger;

  constructor() {
    this.logger = createLogger({
      level: "info",
      format: this.setFormat(),
      transports: this.createTransports(),
    });
  }

  info(message: string): void {
    this.logger.info(message);
  }

  warn(message: string): void {
    this.logger.warn(message);
  }

  error(message: string): void {
    this.logger.error(message);
  }

  private setFormat() {
    return format.combine(
      format.timestamp({ format: "YYYY-MM-DD HH:mm:ss" }),
      format.printf(
        ({ timestamp, level, message }) =>
          `${timestamp} [${level.toUpperCase()}]: ${message}`,
      ),
    );
  }

  private createTransports() {
    return [
      new transports.Console(),
      new DailyRotateFile({
        dirname: path.resolve(process.cwd()),
        filename: "watering-system-%DATE%.log",
        datePattern: "YYYY-MM-DD",
        maxSize: "5m",
        maxFiles: "14d",
      }),
    ];
  }
}
