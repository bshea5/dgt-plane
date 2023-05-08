

def tick args
  set_state args
  args.outputs.labels << [240, 710, 'Press `~` to toggle debug console', 5, 1]

  args.outputs.sprites << { x: 1100,
                            y: 50,
                            w: 128,
                            h: 101,
                            path: 'dragonruby.png',
                            angle: args.state.tick_count }

  args.outputs.labels  << { x: 640,
                            y: 60,
                            text: './mygame/app/main.rb',
                            size_enum: 5,
                            alignment_enum: 1 }

  # [TODO] Debug mode?
  args.outputs.labels << {
    x: 1000,
    y: 710,
    text: "x: #{args.state.player_x} y: #{args.state.player_y}"
  }

  do_simple_player_controls args

  for c in args.state.clouds do
    c.x -= c.s
  end

  args.outputs.sprites << [args.state.player_x, args.state.player_y, 100, 80, 'sprites/dragon-0.png']
  args.outputs.sprites << [args.state.clouds, args.state.fireballs]
end

def set_state args
  args.state.player_x ||= 120
  args.state.player_y ||= 280
  args.state.player_w ||= 100
  args.state.player_h ||= 80
  args.state.player_speed = 15
  args.state.fireballs ||= []
  args.state.clouds ||= 10.times.collect { spawn_cloud(args) }

  if (args.tick_count % 30 == 0)
    args.state.clouds << spawn_cloud(args)
  end

  args.state.clouds.reject! { |c| c.x < 0 - c.w }
  args.state.fireballs.reject! { |f| f.x > args.grid.w }
end

def do_simple_player_controls args
  x, y, s = [args.state.player_x, args.state.player_y, args.state.player_speed]
  up, down, left, right = [args.inputs.up, args.inputs.down, args.inputs.left, args.inputs.right]

  do_fire args

  # slow speed if diagonal movement
  if (up or down) and (left or right)
    s = s / 2
  end

  if left
    x -= s
  elsif right
    x += s
  end

  if up
    y += s
  elsif down
    y -= s
  end

  # args.grid gets screen measurements. Static values, but avoid magic numbers.
  # Let's keep the dragon on screen.
  args.state.player_x = x.clamp(0, args.grid.w - args.state.player_w)
  args.state.player_y = y.clamp(0, args.grid.h - args.state.player_h)
end

def do_fire args
  if args.inputs.keyboard.key_down.z ||
    args.inputs.keyboard.key_down.j
    args.state.fireballs << {
      x: args.state.player_x + args.state.player_w - 12,
      y: args.state.player_y + 10,
      w: 32,
      h: 32,
      path: 'sprites/missile.png',
      flip_horizontally: true
    }
  end

  args.state.fireballs.each do |fireball|
    # speed of dragon plus some to be faster than dragon
    fireball.x += args.state.player_speed + 2

    # args.state.targets.each do |target|
    #   if args.geometry.intersect_rect?(target, fireball)
    #     target.dead = true
    #     fireball.dead = true
    #     args.state.score += 1
    #     args.state.targets << spawn_target(args)
    #   end
    # end
  end
end

def spawn_cloud(args)
  {
    x: randrange(args.grid.w, args.grid.w + 100),
    y: randrange(100, args.grid.h - 100),
    w: 100,
    h: 80,
    s: randrange(1, 5),
    path: 'sprites/cloud.png',
  }
end

# future library funcs?
def randrange low, high
  size = high - low + 1
  rand(size) + low
end
