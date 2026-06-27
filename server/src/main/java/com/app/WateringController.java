package com.app;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import com.app.logger.core.AppLogger;


@RestController
public class WateringController {
    
    private final AppLogger logger;

    public WateringController(AppLogger logger) {
        this.logger = logger;
    }

    @GetMapping("path")
    public String getMethodName() {
        logger.info("Received request for /path endpoint");
        logger.warn("This is a warning message");
        logger.error("This is an error message");
        return "Hello World";
    }

}
