# -*- coding: utf-8 -*- 

'''
    Este script toma ficheros .md y los convierte en una página web HTML5.

    Instalar pip: apt-get install python-pip
    Instalar markdown: pip install markdown
'''

# Dependencias
from os import listdir as ls
import markdown
import codecs


nombre_html = 'memoria.html'

# Índice
indice = '''
    <h2 class="text-muted">Taula de continguts</h1>
    <ul>
        %s
    </ul>
'''
indice_elemento = '''<li><h4><a href='#%s'>%s</a><h3></li>\n'''

# El contenedor que envuelve a un artículo
contenedor = '''
    <div id='%s' class='featurette data-sr'>
        %s
    </div>
<br><hr><br>
'''

def urlify(url):
    return url.replace(' ', '-')


# Cabecera 
def read(file):
    inp = codecs.open(file, mode="r", encoding="utf-8")
    return inp.read()

# Blog
def create_blog(lista):
    blog = ''
    lista = ''
    for fichero in sorted([f for f in ls('./memoria') if f.endswith('.md')]):

        # Abrimos el fichero y lo leemos
        inp = codecs.open('./blog/%s'%fichero, mode="r", encoding="utf-8")
        md = inp.read()

        # Preparamos el html
        nombre = fichero[3:-3]
        url = urlify(nombre).lower()
        data = ( url, markdown.markdown(md) )
        blog += contenedor % data
        lista += indice_elemento % (url, nombre) + '\n'

    return blog, lista

# Montamos el html
lista=u''
blog, lista = create_blog(lista)
html = u'''
{cabecera}


<!-- Cuerpo -->
<div id="sidebar" class="row">

    <!-- Indice -->
    <div class="col-md-3">
        {indices}
    </div>

    <!-- Aquí empiezan los artículos -->
    <div class="col-md-9">
        {blog}
    </div>
</div>

<!-- Pie de página -->
{pie_de_pagina}'''.format(
    cabecera = read('./include/header.html'),
    indices = str((indice % lista)),
    blog = blog,
    pie_de_pagina = read('./include/footer.html'),
)

html = html.replace('<img', '<img class="img-responsive center-block"')

# Guardamos el html
output_file = codecs.open("blog.html", "w+", 
                          encoding="utf-8", 
                          errors="xmlcharrefreplace"
)
output_file.write(html)

