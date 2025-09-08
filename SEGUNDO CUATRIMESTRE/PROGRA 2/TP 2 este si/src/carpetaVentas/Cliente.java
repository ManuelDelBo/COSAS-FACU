package carpetaVentas;

import java.util.UUID;

public class Cliente {
    private String id;
    private String nombre;
    private String mail;
    private int porcentajeDescuento;

    public Cliente() {
    }

    public Cliente(String nombre, String mail, int porcentajeDescuento) {
        this.id = generarID();
        this.nombre = nombre;
        this.mail = mail;
        this.porcentajeDescuento = porcentajeDescuento;
    }
//GETTERS Y SETTERS

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getMail() {
        return mail;
    }

    public void setMail(String mail) {
        this.mail = mail;
    }

    public int getPorcentajeDescuento() {
        return porcentajeDescuento;
    }

    public void setPorcentajeDescuento(int porcentajeDescuento) {
        this.porcentajeDescuento = porcentajeDescuento;
    }

    private String generarID()
    {
        return UUID.randomUUID().toString().substring(0, 8).toUpperCase();
    }

    @Override
    public String toString() {
        return "Cliente{" +
                "id='" + getId() + '\'' +
                ", nombre='" + getNombre() + '\'' +
                ", mail='" + getMail() + '\'' +
                ", porcentajeDescuento=" + getPorcentajeDescuento() +
                '}';
    }
}
