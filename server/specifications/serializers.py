from django.forms import widgets
from rest_framework import serializers
from specifications.models import Specifications
from datetime import datetime

from django.contrib.auth.models import User

class SpecificationsSerializer(serializers.Serializer):
    name = serializers.CharField(required=False, default="specifications")
    upload_url_root = serializers.CharField()
    read_frequency = serializers.FloatField()
    product_id = serializers.IntegerField()
    vendor_id = serializers.IntegerField()

    def restore_object(self, attrs, instance=None):
        if instance:
            instance.upload_url_root = attrs.get('upload_url_root', 
                                                 instance.upload_url_root)
            instance.read_frequency = attrs.get('read_frequency', 
                                                instance.read_frequency)
            instance.product_id = attrs.get('product_id', instance.product_id)
            instance.vendor_id = attrs.get('vendor_id', instance.vendor_id) 
            return instance
        return Specifications(**attrs)