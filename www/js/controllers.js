angular.module('starter.controllers', ['ngCordova'])

.controller('DashCtrl', function($scope) {})
.controller('mycontroller', function($scope, $http, applicationState, $stateParams, $timeout){
// utilities
    $scope.clone = function(val){
      return angular.merge({}, val);
      //return JSON.parse(JSON.stringify(val));
    }

    $scope.isNull = function(val){
      return typeof(val) == "undefined" || null == val;
    }

//controller level variables
    $scope.mapOfPageIdToData = applicationState.mapOfPageIdToData;

   console.log($stateParams);

//common for all the searches we are going to make for this channel
    $scope.key = 'AIzaSyBhLDQTuRp5C7GXssBvBw7ZWB5nGVDLXb4';
    $scope.channelId = 'UCNwW8ly1GHjRi0MxpjSSWzg';
    $scope.youtubeParams = {
      key: $scope.key,
      maxResults:'50',
      part: 'id,snippet',
      order: 'date',
      autoplay: 0
    }

  $scope.playerVideoId=$stateParams.videoId;
  function onYoutubeIframeAPIReady(){
    $scope.player=new YT.Player('player',{
      height:'390',
      width:'640',
      videoId:$scope.playerVideoId,
      events:{
        'onReady':onPlayerReady,
        'onStateChange':onPlayerStateChange
      }
    })
  }
  function stopVideo(){
    $scope.player.stopVideo();
  }
  $scope.destroyPlayer=function(){
    $scope.player.stopVideo();
  }
  $scope.onPlayerReady=function(event){
    event.target.playVideo();
  }
  var done = false;
  $scope.onPlayerStateChange= function(event){
    if(event.data==YT.PlayerState.Playing && !done){
      setTimeout(stopVideo,6000);
      done=true;
    }
  }



    








 
    $scope.visisblePageType = $stateParams.type;
    $scope.pageId = $stateParams.id;
    $scope.page = null;


    $scope.getUrlsInAText = function(text){    
      var urls = $scope.isNull(text) ? null : text.match($scope.urlRegex);
      return urls; 
    }


    $scope.urlRegex = /(\b(https?|ftp):\/\/[A-Z0-9+&@#\/%?=~_|!:,.;-]*[-A-Z0-9+&@#\/%=~_|])/gim;
    $scope.removeUrlsFromDescription = function(text){
      return text.replace($scope.urlRegex, "");
    }
    $scope.samplePlaylistItemListType = {
      urlSuffix : "playlistItems",
      identifier : "playlistId",
      newlyFetchedEntityListHandler : function(response, pageData){
        var videos = pageData.videos;
        angular.forEach(response.items, function(child){
          var video = {};
          video.id = child.snippet.resourceId.videoId;
          video.title = child.snippet.title;
          video.publishedAt = child.snippet.publishedAt;
          var downloadUrls = $scope.getUrlsInAText(child.snippet.description);
          video.downloadUrls = $scope.isNull(downloadUrls) ? null : downloadUrls;
          video.description = $scope.removeUrlsFromDescription(child.snippet.description);
          videos.push(video);
          console.log (child);
        });
        if($scope.isNull(response.nextPageToken)){
          pageData.isEverythingLoaded = true;
        }else{
          pageData.nextPageToken = response.nextPageToken;  
        }
        console.log(pageData);
      }
    };

    $scope.samplePlaylistListType = {
      urlSuffix : "playlists",
      identifier : "channelId",
      newlyFetchedEntityListHandler : function(response, pageData){
        var playlists = pageData.playlists;
        angular.forEach(response.items, function(child){
          var playlist = {};
          playlist.id = child.id;
          playlist.title = child.snippet.title;
          playlist.description = $scope.removeUrlsFromDescription(child.snippet.description);
          playlist.publishedAt = child.snippet.publishedAt;
          playlists.push(playlist);
          console.log (child);
        });
        if($scope.isNull(response.nextPageToken)){
          pageData.isEverythingLoaded = true;
        }else{
          pageData.nextPageToken = response.nextPageToken;  
        }
        console.log(pageData);
      }

    };
    $scope.sampleChannelListItemTypes = {
      type : "video",
      urlSuffix : "search",
      identifier : "channelId",
      newlyFetchedEntityListHandler : function(response, pageData){
        var videos = pageData.videos;
        angular.forEach(response.items, function(child){
          var video = {};
          video.id = child.id.videoId;
          video.title = child.snippet.title;
          video.publishedAt = child.snippet.publishedAt;
          video.description = $scope.removeUrlsFromDescription(child.snippet.description);
          videos.push(video);
          console.log (child);
        });
        if($scope.isNull(response.nextPageToken)){
          pageData.isEverythingLoaded = true;
        }else{
          pageData.nextPageToken = response.nextPageToken;  
        }
        console.log(pageData);
      }
    };

    $scope.getPageType = function(pageType){
      if(pageType == "samplePlaylistItemListType")return $scope.clone($scope.samplePlaylistItemListType);
      if(pageType == "samplePlaylistListType")return $scope.clone($scope.samplePlaylistListType);
      if(pageType == "sampleChannelListItemTypes")return $scope.clone($scope.sampleChannelListItemTypes);
    }


    
    $scope.initializeANewPageData = function(pageId, pageType){

      var sampleDataAPageHoldsAndItNeedsFurther = {
        videos : [],
        playlists : [],
        nextPageToken : undefined,
        isEverythingLoaded : false,
        pageType : null,
        identifier : null
      }
      var pageData = $scope.clone(sampleDataAPageHoldsAndItNeedsFurther);
      pageData.pageType = $scope.getPageType(pageType);
      pageData.identifier = pageId;
      $scope.mapOfPageIdToData[pageId + pageType] = pageData;
    }
    
    $scope.openPage = function(pageId, pageType){
      var pageData = $scope.mapOfPageIdToData[pageId + pageType];
      if($scope.isNull(pageData) || pageData.videos.length == 0){
        $scope.initializeANewPageData(pageId, pageType);
        pageData = $scope.mapOfPageIdToData[pageId + pageType];
        $scope.fetchVideos(pageData);
        
      }      $scope.page = pageData;
      //this is wrong either use page or page id, and not both otherwise inconsistency can be there
      $scope.pageId = pageData.identifier;
      console.log($scope.page)
    }


    $scope.messageUser = function(message){
      //TODO implement it using overlays and shit
      alert(message);
    }
    



    

    $scope.playerVars = {
      rel: 0,
      showinfo: 0,
      modestbranding: 0,
    }

    

    // $scope.updateCurrentlyPlaying = function(video){
    //   $timeout(function({$scope.$apply(function(){
    //     $scope.currentVideoPlaying = video;  
    //   });}));
      
    // }
    $scope.isFetchDisabled = false;
    $scope.fetchVideos = function(pageData){
      pageData.isFetchDisabled = true;
      var nextPageToken = pageData.nextPageToken;
      if(pageData.isEverythingLoaded){
        $scope.messageUser("You have loaded all the videos present on this page");
        pageData.isFetchDisabled = false;
        return;
      }
      var youtubeParams = JSON.parse(JSON.stringify($scope.youtubeParams));
      youtubeParams["type"] = pageData.pageType.type;
      youtubeParams[pageData.pageType.identifier] = pageData.identifier; 
      
      if(!$scope.isNull(nextPageToken)){
        youtubeParams["pageToken"] = nextPageToken;
      }
      youtubeParams = $scope.clone(youtubeParams);
      $scope.pullNewData(youtubeParams, pageData);
      pageData.isFetchDisabled = false;
    }


    $scope.newlyFetchedVideoListHandler = function(response, pageData){
      var videos = pageData.videos;
      angular.forEach(response.items, function(child){
        videos.push(child);
        console.log (child);
      });
      if($scope.isNull(response.nextPageToken)){
        pageData.isEverythingLoaded = true;
      }else{
        pageData.nextPageToken = response.nextPageToken;  
      }
    }
    $scope.pullNewData = function(youtubeParams, pageData){
      var url = 'https://www.googleapis.com/youtube/v3/' + pageData.pageType.urlSuffix;
      $http.get(url, {params:youtubeParams}).success(function(response){
        pageData.pageType.newlyFetchedEntityListHandler(response, pageData);
      });
    }





$scope.getMp3DownloadUrl = function(video){
  return $scope.isNull(video.downloadUrls) ? null : video.downloadUrls[0];
}
$scope.getMp3FileNameForSaving = function(video){
  return video.title;
}
$scope.downloadPath = 'JRM/Taqaareer/MP3/';
$scope.download = function(video){
  ionic.Platform.ready(function(){
             var url = $scope.getMp3DownloadUrl(video);
             var filename = $scope.getMp3FileNameForSaving(video);
             var targetPath = cordova.file.externalRootDirectory + $scope.downloadPath + filename;
 
              $cordovaFileTransfer.download(url, targetPath, {}, true).then(function (result) {
                    video.downloadMessage = 'Saved file on '+targetPath+' success!';
              }, function (error) {
                    video.downloadMessage = 'Error in Downloading file';
              }, function (progress) {
                    video.downloadProgress = (progress.loaded / progress.total) * 100;
              });
      });
}
$scope.openPage($scope.pageId, $scope.visisblePageType);
  })

.controller('ChatsCtrl', function($scope, Chats) {
  // With the new view caching in Ionic, Controllers are only called
  // when they are recreated or on app start, instead of every page change.
  // To listen for when this page is active (for example, to refresh data),
  // listen for the $ionicView.enter event:
  //
  //$scope.$on('$ionicView.enter', function(e) {
  //});

  $scope.chats = Chats.all();
  $scope.remove = function(chat) {
    Chats.remove(chat);
  };
})

.controller('ChatDetailCtrl', function($scope, $stateParams, Chats) {
  $scope.chat = Chats.get($stateParams.chatId);
})

.controller('AccountCtrl', function($scope) {
  $scope.settings = {
    enableFriends: true
  };
});
