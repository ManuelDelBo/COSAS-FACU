package org.eduardomango.practicaspringweb.model.controllers;

import org.eduardomango.practicaspringweb.model.entities.SaleEntity;
import org.eduardomango.practicaspringweb.model.exceptions.SaleNotFoundException;
import org.eduardomango.practicaspringweb.model.services.SaleService;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import java.util.List;

@RestController
@RequestMapping("/ventas")
public class SaleController {

    private final SaleService saleService;

    public SaleController(SaleService saleService) {
        this.saleService = saleService;
    }

    @GetMapping
    public ResponseEntity<List<SaleEntity>> findAll() {
        return ResponseEntity.ok(saleService.findAll());
    }

    @GetMapping("/{id}")
    public ResponseEntity<SaleEntity> findById(@PathVariable long id) {
        try {
            SaleEntity sale = saleService.findById(id);
            return ResponseEntity.ok().body(sale);
        } catch (SaleNotFoundException e) {
            return ResponseEntity.notFound().build();
        }
    }

    @PostMapping
    public ResponseEntity<SaleEntity> save(@RequestBody SaleEntity sale) {
        saleService.save(sale);
        return ResponseEntity.status(201).body(sale);
    }

    @PutMapping("/{id}")
    public ResponseEntity<SaleEntity> update(@PathVariable long id,
                       @RequestBody SaleEntity sale) {
        try {
            sale.setId(id);
            saleService.update(sale);
            return ResponseEntity.ok(sale);
        } catch (SaleNotFoundException e) {
            return ResponseEntity.notFound().build();
        }
    }

    @DeleteMapping("/{id}")
    public ResponseEntity<Void> delete(@PathVariable long id) {
        try {
            saleService.delete(id);
            return ResponseEntity.noContent().build();
        } catch (SaleNotFoundException e) {
            return ResponseEntity.notFound().build();
        }

    }
}
