import { type Logger } from "../../logger/core/logger.js";

export class WateringService {
  constructor(private readonly logger: Logger) {}

  public async waterPlants(): Promise<void> {
    try {
      if (!this.isWateringTime()) {
        this.logger.warn("It's not the designated watering time.");
        return;
      }
      await this.simulateWatering();
      this.logger.info("Watering completed successfully.");
    } catch (error) {
      this.logger.error("Error watering plants.");
      throw error;
    }
  }

  private isWateringTime(): boolean {
    const currentHour = new Date().getHours();
    return currentHour >= 6 && currentHour <= 9;
  }
}
