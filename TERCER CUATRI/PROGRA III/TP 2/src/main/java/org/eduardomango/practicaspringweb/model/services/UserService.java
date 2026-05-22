package org.eduardomango.practicaspringweb.model.services;


import org.eduardomango.practicaspringweb.model.entities.UserEntity;
import org.eduardomango.practicaspringweb.model.exceptions.UserNotFoundException;
import org.eduardomango.practicaspringweb.model.repositories.IRepository;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class UserService {

    private final IRepository<UserEntity> userRepository;

    public UserService(IRepository<UserEntity> userRepository) {
        this.userRepository = userRepository;
    }

    public List<UserEntity> findAll() {
        return userRepository.findAll();
    }
    public UserEntity findById(long id) {
        return userRepository.findAll()
                .stream()
                .filter(user -> user.getId() == id)
                .findFirst()
                .orElseThrow(UserNotFoundException::new);
    }

    public UserEntity findByUsername(String username){
        return userRepository.findAll()
                .stream()
                .filter(user -> user.getUsername().equalsIgnoreCase(username))
                .findFirst()
                .orElseThrow(UserNotFoundException::new);
    }

    public UserEntity findByEmail(String email){
        return userRepository.findAll()
                .stream()
                .filter(user -> user.getEmail().equalsIgnoreCase(email))
                .findFirst()
                .orElseThrow(UserNotFoundException::new);
    }

    public void save(UserEntity user) {
        userRepository.save(user);
    }

    public void delete(long id) {
        UserEntity userAux = findById(id);
        userRepository.delete(userAux);

    }

    public void update(UserEntity user) {
        UserEntity existente = userRepository.findAll()
                .stream()
                .filter(u -> u.getId() == user.getId())
                .findFirst()
                .orElseThrow(() -> new RuntimeException("Usuario no encontrado"));

        existente.setUsername(user.getUsername());
        existente.setEmail(user.getEmail());
        existente.setPassword(user.getPassword());
    }
}
