package Clases;

import Excepciones.DatoInvalidoException;
import ManejoJSON.JSONUtiles;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;

public class Universidad {
    private List<Curso> cursos;

    public Universidad() {
    }

    public List<Curso> getCursos() {
        return cursos;
    }

    public void setCursos(List<Curso> cursos) {
        this.cursos = cursos;
    }

    //MANEJO JSON

    public void cargarDesdeJSON(String ruta)
    {
        try {
            JSONObject json = new JSONObject(JSONUtiles.leer(ruta));
            JSONArray jCursos = json.getJSONArray("cursos");
            List<Curso> cursos = new ArrayList<>();

            for(int i=0;i<jCursos.length();i++)
            {
                JSONObject jCurso = jCursos.getJSONObject(i);
                Curso c = new Curso();
                c.setNombre(jCurso.getString("nombre"));
                c.setCodigo(jCurso.getString("codigo"));
                c.setProfesor(jCurso.getString("profesor"));

                JSONArray jEstudiantes = jCurso.getJSONArray("estudiantes");
                List<Estudiante> estudiantes = new ArrayList<>();

                for(int j=0;j<jEstudiantes.length();j++)
                {
                    JSONObject jEstudiante = jEstudiantes.getJSONObject(j);
                    String nombreEstudiante = jEstudiante.getString("nombre");
                    if(nombreEstudiante == null || nombreEstudiante.isEmpty())
                    {
                        throw new DatoInvalidoException("El estudiante tiene nombre vacío");
                    }
                    Estudiante e = new Estudiante();

                    e.setNombre(jEstudiante.getString("nombre"));
                    e.setLegajo(jEstudiante.getInt("legajo"));

                    JSONArray jActividades = jEstudiante.getJSONArray("actividades");
                    List<Actividad> actividades = new ArrayList<>();

                    for (int k=0;k<jActividades.length();k++)
                    {
                        JSONObject jActividad = jActividades.getJSONObject(k);
                        Actividad a = new Actividad();

                        a.setNombre(jActividad.getString("nombre"));
                        a.setTipo(jActividad.getString("tipo"));

                        JSONArray jNotas = jActividad.getJSONArray("notas");
                        List<Double> notas = new ArrayList<>();

                        for(int l = 0;l<jNotas.length();l++)
                        {
                            double nota = jNotas.getDouble(l);
                            if(nota<0)
                            {
                                throw new DatoInvalidoException("La nota no puede ser negativa");
                            }
                            notas.add(nota);
                        }
                        if(notas.isEmpty())
                        {
                            throw new DatoInvalidoException("La actividad debe tener al menos una nota");
                        }
                        a.setNotas(notas);

                        JSONArray jComentarios = jActividad.getJSONArray("comentarios");
                        List<String> comentarios = new ArrayList<>();

                        for(int m = 0;m<jComentarios.length();m++)
                        {
                            String comentario = jComentarios.getString(m);
                            comentarios.add(comentario);
                        }
                        a.setComentarios(comentarios);
                        actividades.add(a);
                    }
                    e.setActividades(actividades);
                    estudiantes.add(e);
                }
                c.setEstudiantes(estudiantes);
                cursos.add(c);
            }
            this.cursos = cursos;

        } catch (JSONException e) {
            throw new RuntimeException(e);
        } catch (DatoInvalidoException e)
        {
            System.out.println("Error al cargar el estudiante" + e.getMessage());
        }
    }

    public void listarCursos()
    {
        if (cursos == null || cursos.isEmpty()) {
            System.out.println("No hay cursos cargados.");
            return;
        }
        for(Curso c : cursos)
        {
            System.out.println("Curso: " + c.getNombre());
            System.out.println("Profesor: " + c.getProfesor());
            System.out.println("Codigo: " + c.getCodigo());
            System.out.println("Estudiantes: ");

            for(Estudiante e : c.getEstudiantes())
            {
                System.out.println(e.getNombre() + " / Legajo: " + e.getLegajo());
            }
            System.out.println("--------------------");
        }
    }

    public void filtrarPorPromedio(Double promedio)
    {
        System.out.println("PROMEDIO: " + promedio);
        for(Curso c : cursos)
        {
            for(Estudiante e : c.getEstudiantes())
            {
                if(calcularPromedio(e)>=promedio)
                {
                    System.out.println("Alumno: " + e.getNombre() + " super el promedio (" + calcularPromedio(e) + ")");
                }
            }
        }
    }

    public double calcularPromedio(Estudiante estudiante)
    {
        double suma = 0;
        int cantidad = 0;

        for(Actividad a : estudiante.getActividades())
        {
            for(double nota : a.getNotas())
            {
                suma += nota;
                cantidad++;
            }
        }
        if(cantidad == 0)
        {
            return 0;
        }
        return suma/cantidad;
    }

}
