angular.module('starter.services', [])


.service("applicationState", function ApplicationState(){
  var applicationState = this;
  applicationState.mapOfPageIdToData = {};
});
