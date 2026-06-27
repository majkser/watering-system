package com.app;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class WateringApplication {

	public static void main(String[] args) {
		SpringApplication.run(WateringApplication.class, args);

		System.out.println("Server is listening on port 8080");
	}
}
