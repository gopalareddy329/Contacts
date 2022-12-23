from django.contrib import admin
from django.urls import path
from . import views


urlpatterns=[
    path('',views.home,name="home"),
    path('remove/<str:no>/',views.remove,name="remove"),
]