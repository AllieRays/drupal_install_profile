module.exports = function (grunt) {

  //measures the time each task takes
  //@see http://www.html5rocks.com/en/tutorials/tooling/supercharging-your-gruntfile/
  require('time-grunt')(grunt);

  // Project configuration.
  grunt.initConfig({

    compass: {
      options: {
        config: 'config.rb',
        bundleExec: true,
        force: true
      },
      dev: {
        options: {
          environment: 'development'
        }
      },
      dist: {
        options: {
          environment: 'production'
        }
      }
    },

    // combine all .scss files into single styles.scss
    //@see https://www.npmjs.com/package/grunt-sass-globbing
    sass_globbing: {
      scss: {
        files: {
          'sass/styles.scss': 'sass/partials/**/*.scss'
        }
      }
    },

    uglify: {
        dev: {
          options: {
            mangle: false,
            compress: false,
            beautify: true
          },
          files: [{
            expand: true,
            flatten: true,
            cwd: 'js',
            dest: 'js',
            src: ['**/*.js', '!**/*.min.js'],
            rename: function(dest, src) {
              var folder = src.substring(0, src.lastIndexOf('/'));
              var filename = src.substring(src.lastIndexOf('/'), src.length);
              filename = filename.substring(0, filename.lastIndexOf('.'));
              return dest + '/' + folder + filename + '.min.js';
            }
          }]
        },
        dist: {
          options: {
            mangle: true,
            compress: true
          },
          files: [{
            expand: true,
            flatten: true,
            cwd: 'js',
            dest: 'js',
            src: ['**/*.js', '!**/*.min.js'],
            rename: function(dest, src) {
              var folder = src.substring(0, src.lastIndexOf('/'));
              var filename = src.substring(src.lastIndexOf('/'), src.length);
              filename = filename.substring(0, filename.lastIndexOf('.'));
              return dest + '/' + folder + filename + '.min.js';
            }
          }]
        }
      }
    });


    clean: {
      //@see https://github.com/gruntjs/grunt-contrib-clean
      options: {
        force: true,
      },
      css: ['dist/css'],
      js: ['dist/js']
    },




    // watch for file changes and execute named tasks in order listed
    watch: {
      options: {
        livereload: true
      },
      scss: {
        files: ['sass/partials/**/*.scss'],
        tasks: ['clean:css', 'sass_globbing', 'sass'],
        options: {
          spawn: true,
          interrupt: true
        }
      },
      js: {
        files: ['js/{,**/}*.js', '!js/{,**/}*.min.js'],
        tasks: ['clean:js', 'uglify:scripts'],
        options: {
          spawn: true,
          interrupt: true
        }
      }

    }
  });

  //These should be in alphabetical order
  grunt.loadNpmTasks('grunt-contrib-compass');
  grunt.loadNpmTasks('grunt-sass-globbing');
  grunt.loadNpmTasks('grunt-contrib-uglify');
  grunt.loadNpmTasks('grunt-uncss');
  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-contrib-clean');
  grunt.loadNpmTasks('grunt-newer');

  // by default, execute these tasks
  grunt.registerTask('default', ['clean', 'sass_globbing', 'sass', 'uglify']);
};
