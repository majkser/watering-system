package com.app.logger.infra;

import org.springframework.beans.factory.InjectionPoint;
import org.springframework.beans.factory.config.ConfigurableBeanFactory;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Scope;

import com.app.logger.core.AppLogger;

@Configuration
public class Slf4jAppLoggerConfig {

    @Bean
    @Scope(ConfigurableBeanFactory.SCOPE_PROTOTYPE)
    public AppLogger appLogger(InjectionPoint injectionPoint) {
        Class<?> clazz = injectionPoint.getMember().getDeclaringClass();
        
        return new Slf4jAppLogger(clazz);
    }
}
