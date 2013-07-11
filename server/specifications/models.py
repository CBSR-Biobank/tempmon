from django.db import models
from pygments.lexers import get_all_lexers
from pygments.styles import get_all_styles
from pygments.lexers import get_lexer_by_name
from pygments.formatters.html import HtmlFormatter
from pygments import highlight
# Create your models here.

class Specifications(models.Model):
    name = models.TextField(default="specifications")
    upload_url_root = models.TextField()
    read_frequency = models.FloatField()
    product_id = models.IntegerField()
    vendor_id = models.IntegerField()
    
    class Meta:
        ordering = ('name', 'read_frequency',)