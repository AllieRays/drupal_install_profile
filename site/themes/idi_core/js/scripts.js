(function($) {

  var desk = 70;
  var tab = 50;
  var navigation;
  var previousState;

  function widthToEm(width) {
    return (width / parseFloat($("body").css("font-size")));
  }

  //Initiate Burger Control
  Drupal.behaviors.THEME_FOLDER_NAME_menu_burger_behavior = {
    attach: function(context, settings) {
      $('.l-region--navigation #main-menu-burger', context).once('burger', function() {
        $(this).click(function() {
          $('#block-system-main-menu').slideToggle('slow');
        });
      });
    }
  };

  function resize_menu() {
    if (widthToEm($(window).width()) < tab) {
      $('#block-system-main-menu').css('display', 'none');
      $('#main-menu-burger').css('display', 'block');
    } else {
      $('#block-system-main-menu').css('display', 'block');
      $('#main-menu-burger').css('display', 'none');
    }
  }
  resize_menu();
  $(window).resize(function() {
    resize_menu();
  });


    $(document).ready(function() {
        $(".flip-button").prepend( "<div class='cube'><span class='flip-button'>Read More</span><span class='button-bottom'>Read More</span></div>" );
        $('a.flip-button').removeClass('flip-button').addClass('three-d');
     //   $('.button').clone().appendTo('.cube');
     //   $('.button:last-child').addClass('button-flip').removeClass('button');
     //   //all links that start with "http" should open in a new browser window

    });

    $(document).ready(function() {
        //$('.node.node--question').hide();
        console.log('answer');
        $(".field--name-field-question-title").click(function() {
            $(this).parent().children(".field--name-field-answer").slideToggle(500); });
    });

})(jQuery);
