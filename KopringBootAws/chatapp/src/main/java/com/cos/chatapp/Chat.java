package com.cos.chatapp;

import java.time.LocalDateTime;

import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document; 

import lombok.Data;

@Data
@Document(collection = "chat")
public class Chat {
	
	@Id
	private String id;
	private String msg;
	private String sender;
	private String receiver;
	
	private LocalDateTime createdAt;

	public void setCreatedAt(LocalDateTime now) {
		// TODO Auto-generated method stub
		this.createdAt = now;
	}
}

