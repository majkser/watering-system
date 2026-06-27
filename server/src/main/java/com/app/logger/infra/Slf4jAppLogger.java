package com.app.logger.infra;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.app.logger.core.AppLogger;

public class Slf4jAppLogger implements AppLogger{
    
    private final Logger logger;

    public Slf4jAppLogger(Class<?> clazz) {
        this.logger = LoggerFactory.getLogger(clazz);
    }

    @Override
    public void info(String message) {
        logger.info(message);
    }

    @Override
    public void warn(String message) {
        logger.warn(message);
    }

    @Override
    public void error(String message) {
        logger.error(message);
    }
}
