<!-- Intro loader -->
<!-- <div class="mask">
    <div id="intro-hcl"><img src="/sites/all/themes/md_alpine/img/hcl.gif"/></div>
    <div id="intro-loader"><img src="/sites/all/themes/md_alpine/img/load_bar.gif"/></div>
</div> -->
<!-- Intro loader -->

<?php if($page['navigation']):?>
    <?php print render($page['navigation']);?>
<?php endif;?>
<?php print $messages;?>

<?php if($page['header']):?>
    <?php print render($page['header']);?>
<?php endif;?>

<?php if($page['front_welcome_note']):?>
<!-- Welcome Note Section -->
    <section id="welcome-note" class="section-content">
        <?php print render($page['front_welcome_note']);?>
    </section>
<!-- Welcome Note Section -->
<?php endif;?>

<?php if($page['about']):?>
<!-- About Section -->
    <section id="about" class="section-content  dark-bg">
        <?php print render($page['about']);?>
    </section>
<!-- About Section -->
<?php endif;?>

<?php if($page['culture']):?>
<!-- culture Section -->
    <section id="culture" class="section-content">
        <?php print render($page['culture']);?>
    </section>
<!-- culture Section -->
<?php endif;?>

<?php if($page['philanthropic']):?>
<!-- philanthropic Section -->
    <section id="philanthropic" class="section-content  dark-bg">
        <?php print render($page['philanthropic']);?>
    </section>
<!-- philanthropic Section -->
<?php endif;?>

<?php if($page['engagement']):?>
<!-- engagement Section -->
    <section id="engagement" class="section-content">
        <?php print render($page['engagement']);?>
    </section>
<!-- engagement Section -->
<?php endif;?>

<?php if($page['testimonial']):?>
<!-- engagement Section -->
    <section id="testimonial" class="section-content  dark-bg">
        <?php print render($page['testimonial']);?>
    </section>
<!-- testimonial Section -->
<?php endif;?>


<?php if($page['parallax_one']):?>
    <!-- Parallax Container -->
        <div id="one-parallax" class="parallax"  data-stellar-background-ratio="0.6" data-stellar-vertical-offset="20">
            <?php print render($page['parallax_one']);?>
        </div>
    <!-- Parallax Container -->
<?php endif;?>

<?php if($page['service']):?>
    <!-- Service Section -->
    <section id="service" class="section-content">
        <?php print render($page['service']);?>
    </section>
    <!-- Service Section -->
<?php endif;?>

<?php if($page['parallax_two']):?>
    <div id="two-parallax" class="parallax" data-stellar-background-ratio="0.6" data-stellar-vertical-offset="20">
        <?php print render($page['parallax_two']);?>
    </div>
    <!-- Parallax Container -->
<?php endif;?>

<?php if($page['portfolio']):?>
    <!-- Portfolio Section -->
    <section id="portfolio" class="section-content">
        <?php print render($page['portfolio']);?>
    </section>
    <!-- Portfolio Section -->
<?php endif;?>

<?php if($page['parallax_three']):?>
    <!-- Parallax Container -->
    <div id="three-parallax" class="parallax" data-stellar-background-ratio="0.6" data-stellar-vertical-offset="20">
        <?php print render($page['parallax_three']);?>
    </div>
    <!-- Parallax Container -->
<?php endif;?>

<?php if($page['team']):?>
    <!-- Team Section -->
    <section id="team" class="section-content">
        <?php print render($page['team']);?>
    </section>
    <!-- Team Section -->
<?php endif;?>

<?php if($page['parallax_four']):?>
    <!-- Parallax Container -->
    <div id="four-parallax" class="parallax" data-stellar-background-ratio="0.6" data-stellar-vertical-offset="20">
        <?php print render($page['parallax_four']);?>
    </div>
    <!-- Parallax Container -->
<?php endif;?>

<?php if($page['client']):?>
    <!-- Client Section -->
    <section id="client" class="section-content">
        <?php print render($page['client']);?>
    </section>
    <!-- Client Section -->
<?php endif;?>

<?php if($page['parallax_five']):?>
    <!-- Parallax Container -->
    <div id="five-parallax" class="parallax" data-stellar-background-ratio="0.6" data-stellar-vertical-offset="20">
        <?php print render($page['parallax_five']);?>
    </div>
    <!-- Parallax Container -->
<?php endif;?>

<?php if($page['pricing']):?>
    <!-- Pricing Section -->
    <section id="pricing" class="section-content">
        <?php print render($page['pricing']);?>
    </section>
    <!-- Pricing Section -->
<?php endif;?>

<?php if($page['parallax_six']):?>
    <!-- Parallax Container -->
    <div id="six-parallax" class="parallax" data-stellar-background-ratio="0.6" data-stellar-vertical-offset="20">
        <?php print render($page['parallax_six']);?>
    </div>
    <!-- Parallax Container -->
<?php endif;?>

<?php if($page['blog']):?>
    <!-- Blog Section -->
    <section id="blog" class="section-content timeline-content bgdark">
        <?php print render($page['blog']);?>
    </section>
    <!-- Blog Section -->
<?php endif;?>

<?php if($page['parallax_seven']):?>
    <!-- Parallax Container -->
    <div id="seven-parallax" class="parallax" data-stellar-background-ratio="0.6" data-stellar-vertical-offset="20">
        <?php print render($page['parallax_seven']);?>
    </div>
    <!-- Parallax Container -->
<?php endif;?>

<?php if($page['contact']):?>
    <!-- Contact Section -->
    <section id="contact" class="section-content">
        <?php print render($page['contact']);?>
    </section>
    <!-- Contact Section -->
<?php endif;?>

<?php if($page['footer']):?>
    <?php print render($page['footer']);?>
<?php endif;?>
