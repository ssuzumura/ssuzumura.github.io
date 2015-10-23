/* ===================================================================

 * スムーススクロール

=================================================================== */
$(function() {
   // #で始まるアンカーをクリックした場合に処理
   $('a[href^=#]').click(function() {
      // スクロールの速度
      var speed = 400;// ミリ秒
      // アンカーの値取得
      var href= $(this).attr("href");
      // 移動先を取得
      var target = $(href == "#" || href == "" ? 'html' : href);
      // 移動先を数値で取得
      var position = target.offset().top;
      // スムーススクロール
      $($.browser.safari ? 'body' : 'html').animate({scrollTop:position}, speed, 'swing');
      return false;
   });
});

/*
* ポップアップ表示
*/
$(function() { 
  $(".popup").mouseover(function(e) {
    var pObj = $(".popup_window");
    if (pObj.length == 0) {
      pObj = $("<div/>").addClass("popup_window").appendTo($("body"));
    }
    pObj.text($(this).attr("data-message"));
    pObj.show(500);
   }).mouseout(function() {
    $(".popup_window").text("").hide("fast");
  }); 
});
