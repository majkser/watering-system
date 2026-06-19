import { type Logger } from "../../logger/core/logger.js";

export class WateringController {
  constructor(
    private readonly wateringService: any,
    private readonly logger: Logger,
  ) {}

  public async waterPlants(req: any, res: any): Promise<void> {
    try {
      await this.wateringService.waterPlants();
      this.logger.info("Watering completed successfully.");
      res.status(200).json({ message: "Watering completed successfully." });
    } catch (error) {
      this.logger.error("Error watering plants.");
      res.status(500).json({ message: "Error watering plants.", error });
    }
  }
}
