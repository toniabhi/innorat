/*------------------------------------------------------------------------
 # MegaSlide - Sep 17, 2013
 # ------------------------------------------------------------------------
 # Designed & Handcrafted by MegaDrupal
 # Websites:  http://www.megadrupal.com -  Email: info@megadrupal.com
 # Author: BaoNV
 ------------------------------------------------------------------------*/

(function(e){var t=.07,n=7,r=218,i='<div class="mdf-item">'+'      <div class="mdi-view"><a href="#" class="btn-viewlayer"></a></div>'+'<div class="mdi-name">'+'    <span class="mdit-type">[image]</span>'+'    <span class="title"></span>'+'    <a href="#" class="btn-deletelayer"></a>'+'    <a href="#" class="btn-clonelayer"></a>'+"</div>"+'    <div class="mdtl-times"><div class="mdi-frame"></div></div>'+"</div>";MegaSlider.Timeline=function(e){this.panel=e};MegaSlider.Timeline.prototype={constructor:MegaSlider.Timeline,init:function(){var i=this;e("#mdf-timeline").tinyscrollbar();e("#slideshow-time").css("left",6e3*t);e("#timeline-items").width(6e3*t+r);e(document).on("click","a.btn-viewlayer",function(){var t=e(this).parent().parent();var n=t.data("box");if(n!=null){if(e(this).hasClass("active")){n.show();n.attr("ishidden","false");t.removeClass("box-hide");e(this).removeClass("active")}else{n.hide();n.attr("ishidden","true");n.removeClass("ui-selected");t.addClass("box-hide");i.panel.triggerChangeSelectItem();e(this).addClass("active")}}return false});e(document).on("click","a.btn-deletelayer",function(){var t=e(this).parent().parent();var n=t.data("box");if(n!=null){t.remove();n.remove();i.panel.triggerChangeSelectItem()}return false});e(document).on("click","a.btn-clonelayer",function(){var t=e(this).parent().parent();var n=t.data("box");if(n!=null){i.panel.cloneBoxItem(n)}return false});e("#timeline-items").sortable({handle:".mdi-name",update:function(e,t){i.triggerChangeOrderItem()},placeholder:"mdf-item"});e("#slideshow-time").draggable({axis:"x",grid:[n,20],containment:"parent",drag:function(e,t){if(t.position.left<=i.maxStart+n)return false;return i.updateTimelineWidth()}})},changeSelectItem:function(e){this.selectedItem=e;this.triggerChangeSelectItem()},triggerChangeSelectItem:function(){e("#timeline-items > div.mdf-item.active").removeClass("active");if(this.selectedItem!=null){var t=this.selectedItem.data("timeline");if(t!=null){e(t).addClass("active")}}},setTimelineWidth:function(n){if(n){e("#slideshow-time").css("left",n*t);this.updateTimelineWidth()}},updateTimelineWidth:function(){var n=this;var i=e("#slideshow-time").position().left;this.panel.setTimelineWidth(Math.round(i/t));e("#timeline-items").width(r+i);e("#timeline-items .mdf-item").each(function(){var r=e(this).find(".mdi-frame");var s=e(this).data("box");if(s!=null&&r.position().left+r.width()>i){r.width(i-r.position().left);s.data("stoptime",i/t);n.panel.changeTimelineValue()}});return true},addTimelineItem:function(s,o){var u=e(i).clone(),a=this;u.find(".mdit-type").html("["+s+"]");var f=o.data("title");u.find("span.title").html(f);var l=o.data("starttime")?o.data("starttime"):0;var c=o.data("stoptime")?o.data("stoptime"):Math.round((e("#timeline-items").width()-r)/t);if(c>l){u.find("div.mdi-frame").css({left:l*t,width:(c-l)*t});if(o.data("starttime")==null||o.data("stoptime")==null){o.data("starttime",l);o.data("stoptime",c);this.panel.changeTimelineValue()}}u.data("box",o);e("#timeline-items").prepend(u);u.find("div.mdi-frame").draggable({containment:"parent",grid:[n,20],stop:function(n,r){var i=e(this).parent().parent();var s=i.data("box");if(s!=null){var o=e(r.helper).position();s.data("starttime",Math.round(o.left/t));s.data("stoptime",Math.round((o.left+e(r.helper).width())/t));if(s.hasClass("ui-selected")){a.panel.triggerChangeSettingItem()}}a.changeMaxStart()}});u.find("div.mdi-frame").resizable({handles:"e, w",containment:"parent",minWidth:2*n,grid:[n,20],stop:function(n,r){var i=e(this).parent().parent();var s=i.data("box");if(s!=null){var o=e(r.helper).position();s.data("starttime",Math.round(o.left/t));s.data("stoptime",Math.round((o.left+e(r.helper).width())/t));if(s.hasClass("ui-selected")){a.panel.triggerChangeSettingItem()}}a.changeMaxStart()}});u.click(function(){if(!e(this).hasClass("active")&&!e(this).hasClass("box-hide")){var t=e(this).data("box");if(t!=null){a.panel.changeSelectItem(t)}}});o.data("timeline",u);e("#mdf-timeline").tinyscrollbar_update("relative")},changeMaxStart:function(){var t=0;e("#timeline-items .mdtl-times").each(function(){var n=e(this).find("div.mdi-frame").position().left;if(n>t){t=n}});this.maxStart=t},changeSelectItem:function(e){this.selectedItem=e;this.triggerChangeSelectItem()},triggerChangeSelectItem:function(){e("#timeline-items > div.mdf-item.active").removeClass("active");if(this.selectedItem!=null){var t=this.selectedItem.data("timeline");if(t!=null){e(t).addClass("active")}}},triggerChangeOrderItem:function(){e("#timeline-items .mdf-item").each(function(t){var n=e(this).data("box");if(n!=null){n.data("zindex",1e3-t);n.css("z-index",1e3-t)}})},changeSelectedItemTitle:function(){if(this.selectedItem!=null){var t=this.selectedItem.data("timeline");if(t!=null){var n=this.selectedItem.data("title");e(t).find("span.title").html(n)}}},setTimelineWidth:function(n){if(n){e("#slideshow-time").css("left",n*t);this.updateTimelineWidth()}},changeActivePanel:function(){e("#timeline-items").html("");var n=this.panel.getTimelineWidth();if(n!=null){this.setTimelineWidth(n)}else this.panel.setTimelineWidth(e("#slideshow-time").position().left/t);var r=this.panel.getAllItemBox();r.sort(function(t,n){var r=parseInt(e(t).data("zindex"));var i=parseInt(e(n).data("zindex"));return r<i?-1:r>i?1:0});var i=this;r.each(function(){i.addTimelineItem(e(this).data("type"),e(this))})}}})(jQuery)