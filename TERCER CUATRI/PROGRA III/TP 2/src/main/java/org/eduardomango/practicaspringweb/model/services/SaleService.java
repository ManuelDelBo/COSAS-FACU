package org.eduardomango.practicaspringweb.model.services;

import org.eduardomango.practicaspringweb.model.entities.ProductEntity;
import org.eduardomango.practicaspringweb.model.entities.SaleEntity;
import org.eduardomango.practicaspringweb.model.entities.UserEntity;
import org.eduardomango.practicaspringweb.model.exceptions.SaleNotFoundException;
import org.eduardomango.practicaspringweb.model.repositories.IRepository;
import org.springframework.stereotype.Service;

import java.time.LocalDate;
import java.util.List;

@Service
public class SaleService {
    private final IRepository<SaleEntity> saleRepository;
    private final IRepository<UserEntity> userRepository;
    private final IRepository<ProductEntity> productRepository;

    public SaleService(IRepository<SaleEntity> saleRepository,
                       IRepository<UserEntity> userRepository,
                       IRepository<ProductEntity> productRepository) {
        this.saleRepository = saleRepository;
        this.userRepository = userRepository;
        this.productRepository = productRepository;
    }

    public List<SaleEntity> findAll() {
        return saleRepository.findAll();
    }

    //BUSCAR POR ID
    public SaleEntity findById(long id) {
        return saleRepository.findAll()
                .stream()
                .filter(x -> x.getId() == id)
                .findFirst()
                .orElseThrow(SaleNotFoundException::new);
    }
    //SEARCH BY CLIENT
    public List<SaleEntity> findByClient(long id) {
        return saleRepository.findAll()
                .stream()
                .filter(sale -> sale.getClient().getId() == id)
                .toList();
    }

    //SEARCH BY DATE
    public List<SaleEntity> findByDate(LocalDate date) {
        return saleRepository.findAll()
                .stream()
                .filter(sale -> sale.getSaleDate().equals(date))
                .toList();
    }

    //ADD SALE
    public void save(SaleEntity sale) {
        saleRepository.save(sale);
    }

    //DELETE SALE
    public void delete(long id) {
        SaleEntity saleAux = findById(id);
        saleRepository.delete(saleAux);
    }

    //UPDATE SALE
    public void update(SaleEntity sale) {
        SaleEntity exist = saleRepository.findAll()
                .stream()
                .filter(s -> s.getId() == sale.getId())
                .findFirst()
                .orElseThrow(() -> new SaleNotFoundException("Usuario no encontrado"));

        exist.setProducts(sale.getProducts());
        exist.setQuantity(sale.getQuantity());
        exist.setClient(sale.getClient());
        exist.setSaleDate(sale.getSaleDate());
    }
}
