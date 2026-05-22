package clases;

import java.util.List;

public abstract class Producto {
    private String tipo;
    private String nombre;
    private String marca;
    private double precio;
    private int cantidadDisponible;
    private String seccionTienda;

    List<Especificacion> especificacions;
    List<Embalaje> embalajesDisponibles;

    public Producto() {
    }

    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public double getPrecio() {
        return precio;
    }

    public void setPrecio(double precio) {
        this.precio = precio;
    }

    public int getCantidadDisponible() {
        return cantidadDisponible;
    }

    public void setCantidadDisponible(int cantidadDisponible) {
        this.cantidadDisponible = cantidadDisponible;
    }

    public String getSeccionTienda() {
        return seccionTienda;
    }

    public void setSeccionTienda(String seccionTienda) {
        this.seccionTienda = seccionTienda;
    }

    public List<Especificacion> getEspecificacions() {
        return especificacions;
    }

    public void setEspecificacions(List<Especificacion> especificacions) {
        this.especificacions = especificacions;
    }

    public List<Embalaje> getEmbalajesDisponibles() {
        return embalajesDisponibles;
    }

    public void setEmbalajesDisponibles(List<Embalaje> embalajesDisponibles) {
        this.embalajesDisponibles = embalajesDisponibles;
    }
}
